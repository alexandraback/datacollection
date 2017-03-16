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

fn = 'bullseye.in'
fn = '/home/vivanov/Downloads/A-small-attempt5.in'
#fn = '/home/vivanov/Downloads/C-large-practice (4).in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            r,t = [int (k) for k in lines[i].split(' ')]
            i += 1
            l.append({ 'r' : r, 't':  t})
        return l

l = process_input(fn)
print(l)



@tailrecursive
def draw(state, r, now_black, n):
    if now_black:
        paint_needed = ((r + 1)**2 - r**2)
        if paint_needed <= state['t']:
            state['t'] -= paint_needed
            n += 1
            r += 1
            now_black = not now_black
            return draw(state, r, now_black, n)
        else : 
            return n
    else :
        r +=1 
        now_black = not now_black
        return draw(state, r, now_black, n)
        
def calc(state):
    i = 1
    while True:
        state['t'] -= ( (state['r'] + 2 * i - 1) ** 2 - (state['r'] + 2 * i-2) ** 2 )
        if state['t'] >= 0:
            i += 1
        else : 
            return i-1
        
        
            

#print(draw(l[3], l[3]['r'], True, 0))
#print(calc(l[4]))
    
    
with open('bullseye.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        print (i, l[i])
        #res = calc(l[i])
        res = (draw(l[i], l[i]['r'], True, 0))
        #print (res - res1)
        to_write.append(('Case #%s: ' %(i+1)) + str(res) + '\n')
    f.writelines(to_write)


    
