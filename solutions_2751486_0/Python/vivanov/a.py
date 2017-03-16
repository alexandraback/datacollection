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


fn = 'a.in'
fn = '/home/vivanov/Downloads/A-small-attempt0 (1).in'
#fn = '/home/vivanov/Downloads/A-large-practice (1).in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            s, n = lines[i].split(' ')
            n = int(n)
            i += 1
            l.append( {'name': list(s), 'n' : n})
        return l

import copy
import re


l = process_input(fn)
print(l)

def count(l, n):
    l = ''.join([i if i not in  ['a', 'e', 'i', 'o', 'u'] else ' ' for i in l ])
    p = l.split(' ')
    return max([len(i) for i in p]) >= n

def divide(l):
    res = []
    for i in range(len(l)):
        for k in range(i+1, len(l)+1):
            res.append(list(l[i:k]))
    return res
            
print(divide(range(4)))

def search(state):
    l = state['name']
    n = state['n']
    divided = divide(l)
    return sum([count(i,n) for i in divided])

#print(search(l[3]))

with open('a.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        to_write.append(('Case #%s: ' %(i+1)) + str(search(l[i])) + '\n')
    f.writelines(to_write)

    
    

             
    
    
    
    
    


