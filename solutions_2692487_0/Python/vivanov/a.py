from threading import currentThread

class TailRecursiveCall(Exception):
    pass

class Rec_f(object):
    def __init__(self, func):
        self.tr_d = {}
        self.func = func

    def __call__(self, *args, **kw):
        self.args = args
        self.kw = kw
        thread = currentThread()
        if thread not in self.tr_d:
            self.tr_d[thread] = {}
            self.tr_d[thread]["depth"] = 0
        self.tr_d[thread]["depth"] += 1
        # Record the arguments passed to function on this thread
        self.tr_d[thread]["args"] = args
        self.tr_d[thread]["kw"] = kw
        depth =  self.tr_d[thread]["depth"]
        # If we are re-entering the same function on the same thread:
        if depth > 1:
            # Effectively detours execution to the "Landing Point",
            # but two execution frames above the current one:
            raise TailRecursiveCall 
        over = False
        while not over:
            over = True
            args = self.tr_d[thread]["args"]
            kw = self.tr_d[thread]["kw"]
            try:
                # Execute the function with the latest arguments for this thread.
                result = self.func(*args, **kw)
            except TailRecursiveCall:
                # Landing point if the function tried to recurse itself.
                # Two execution frames above.
                self.tr_d[thread]["depth"] -= 1
                over = False
        self.tr_d[thread]["depth"] -= 1
        return result

def tailrecursive(func):
    return Rec_f(func)

import itertools
import copy

fn = 'a.in'
fn = '/home/vivanov/Downloads/A-small-attempt0.in'
#fn = '/home/vivanov/Downloads/C-large-practice (3).in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            a = [int (k) for k in lines[i].split(' ')][0]
            i += 1
            m = [int (k) for k in lines[i].split(' ')]
            i += 1
            l.append({ 'a' : a , 'm' : sorted(m), 'score' : 0})
        return l

l = process_input(fn)
print(l)


def not_solved (state):
    state = dict(state.items())
    a = state['a']
    m = state['m']
    for i in range(len(m)):
        if a <= m[i]:
            return i
        else : 
            a += m[i]

#print(not_solved(l[1]))

def cover(a,b,l):
    if a > b :
        return l
    else :
        x = a - 1
        l.append(x) 
        a += x
        return cover(a,b,l)
    
print(cover(2,6,[]))
    
    

def gen_possible_states(state0):
    k = not_solved(state0)
    if k != None: 
        state = dict(state0.items())
        states = []
        state['score'] += len(state['m'][k:])        
        state['m'] = state['m'][:k]
        states.append(state)
        
        if state0['a'] > 1:
            state = dict(state0.items())
            covered = cover( sum(state['m'][:k]) + state['a'], state['m'][k], [] )
            state['m'] = state['m'][:k] + covered + state['m'][k:]
            state['score'] += len(covered) 
            states.append(state)
        return states

#print(gen_possible_states(l[1]))    
    

def search(front, visited):
    if front:
        front = sorted(front, key = lambda x : x['score'])
        state = front[0]
        front = front[1:]
        if state not in visited:
            states = gen_possible_states(state)
            if states:
                front += states
                visited.append(state)
            else : 
                return state['score']
        return search(front, visited)

print(search([l[3]], []))



with open('a.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        print (i, l[i])
        to_write.append(('Case #%s: ' %(i+1)) + str(search([l[i]], [])) + '\n')
    f.writelines(to_write)



            
