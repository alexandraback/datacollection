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

fn = 'b.in'
fn = '/home/vivanov/Downloads/B-small-attempt3.in'
#fn = '/home/vivanov/Downloads/A-large.in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            n,x,y = [int (k) for k in lines[i].split(' ')]
            i += 1
            l.append({ 'n' : n, 'x' : x, 'y':y  })
        return l

l = process_input(fn)
print(l)

import math
def search(state):
    n = state['n']
    x = abs(state['x'])
    y = abs(state['y'])
    flag = True
    i = 1
    while flag:
        size = i * i / 2 + i / 2
        if size == n :
            if x <= i and y <= i: 
                return 1
            else : 
                return 0
        if size > n : 
            flag = False
        if size < n : 
            i += 2
    i -= 2
    size = i * i / 2 + i / 2
    if x + y == i + 1 and y < i + 1  : 
        d = n - size
        n = int(d)
        return sum ( [ math.factorial(n) / (math.factorial(k) * math.factorial(n - k)) / (2 ** n) for k in range(y+1, n + 1) ])
    elif x < i and y < i :
        return 1 
    else : 
        return 0
    
print(l[6])
print(search(l[6]))    
    
    
with open('b.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        print (i, l[i])
        to_write.append(('Case #%s: ' %(i+1)) + str(search(l[i])) + '\n')
    f.writelines(to_write)


    