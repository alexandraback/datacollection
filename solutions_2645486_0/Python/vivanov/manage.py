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
import math

fn = 'manage.in'
fn = '/home/vivanov/Downloads/B-small-attempt0.in'
#fn = '/home/vivanov/Downloads/A-large.in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            e,r,n = [int (k) for k in lines[i].split(' ')]
            i += 1
            vs = [int (k) for k in lines[i].split(' ')]
            i += 1
            l.append({ 'vs' : vs, 'e':  e, 'r' : r, 'max_e' : e, 'score' : 0})
        return l

l = process_input(fn)
print(l)


def act(state0, a):
    state = copy.deepcopy(state0)
    v = state['vs'][0]
    state['vs'] = state['vs'][1:] 
    state['e'] += -a + state['r']
    state['score'] +=  v * a
    state['e'] = min(state['max_e'], state['e'])
    return state
    

def possible_states(state):
    new_states = []
    for i in range(0, state['e'] + 1):
        new_state = act(state, i)
        new_states.append(new_state)
    return new_states
   

#print(possible_states(l[0]))   
 
 

def seen_better(state, visited):
    for i in visited:
        if len(state['vs']) <= len(i['vs']) and state['score'] <= i['score'] and state['e'] <= i['e']:
            return True
    

@tailrecursive
def search(front, visited, accum):
    if front : 
        state = front[0]
        front = front[1:]
        visited.append(state)
        if not state['e'] or not state['vs']:
            accum.append(state['score'])
        else : 
            for i in possible_states(state):
                if not seen_better(i, front + visited):
                    front.append(i)
        return search(front, visited, accum)
    else : 
        return max(accum)
     
#print(search([l[0]], [], []))    
    


with open('manage.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        print (i, l[i])
        to_write.append(('Case #%s: ' %(i+1)) + str( search([l[i]], [], []) ) + '\n')
    f.writelines(to_write)

    
    
    
