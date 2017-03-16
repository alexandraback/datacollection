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


fn = 'b.in'
fn = '/home/vivanov/Downloads/B-small-attempt1.in'
#fn = '/home/vivanov/Downloads/C-large.in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            x, y = [int(k) for k in lines[i].split(' ')] 
            i += 1
            l.append((x, y))
        return l

import copy
import re


l = process_input(fn)
print(l)


def prod_letter (is_x, d):
        if is_x :
            if d > 0 : 
                'E'
            else : 
                'W'
        else  :
            if d < 0 : 
                'N'
            else : 
                'S'
    
        

def do_one(start, target, step, is_x):
    d = target - start
    if abs(d) == step:
        if is_x :
            if d > 0 : 
                return ['E']
            else : 
                return ['W']
        else  :
            if d < 0 : 
                return ['N']
            else : 
                return ['S']
    else:
        if is_x:
            if d > 0:
                l = [ 'E' if i % 2 == 1 else 'W' for i in range(abs(d) * 2) ]
            else : 
                l = [ 'W' if i % 2 == 1 else 'E' for i in range(abs(d) * 2) ]
        else : 
            if d > 0:
                l = [ 'N' if i % 2 == 1 else 'S' for i in range(abs(d) * 2) ]
            else : 
                l = [ 'S' if i % 2 == 1 else 'N' for i in range(abs(d) * 2) ]
        return  l
    
        
            
    
print(do_one(0,1,3,True))
    
def search(x,y):
    if abs(x) <= abs(y):
        path = do_one(0,x,1, True)
        path += do_one(0,y,1 + len(path), False)
    else : 
        path = do_one(0,y,1, False)
        path += do_one(0,x,1 + len(path), True)
    return  ''.join(path)

print(search(l[0][0], l[0][1]))

    
         
    
with open('b.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        print(i)
        to_write.append(('Case #%s: ' %(i+1)) + str(search(l[i][0], l[i][1] )) + '\n')
    f.writelines(to_write)

    
    
    
    
    
    
    
