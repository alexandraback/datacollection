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


fn = 'c.in'
fn = '/home/vivanov/Downloads/C-small-attempt0.in'
#fn = '/home/vivanov/Downloads/A-large (1).in'


def process_input(fn):
    with open(fn) as f:
        lines = f.read().splitlines()[1:]
        l = []
        i = 0
        while i < len(lines):
            num = int(lines[i].split(' ')[0])
            i += 1
            tribes = []
            for _ in range(num):
                d, n, w, e, s, delta_d, delta_p ,delta_s = [int(k) for k in lines[i].split(' ')] 
                tribes.append( ( d, n, w, e, s, delta_d, delta_p ,delta_s ))
                i += 1
            l.append(tribes)
        return l

import copy
import re


l = process_input(fn)
print(l)


def gen_points(a, b):
    x = a
    l = []
    while x <= b:
        l.append(x)
        x += 0.5
    return l
        

def one_run (wall, tribe):
    d, n, w, e, s, delta_d, delta_p ,delta_s = tribe
    if min([ wall.get(i, 0) for i in gen_points(w,e) ]) < s:
        return (w,e), s
        
def gen_tribes(tribes0):
    tribes = []
    for tribe in tribes0:
        d, n, w, e, s, delta_d, delta_p ,delta_s = tribe
        tribes.append(tribe)
        for _ in range(n-1):
            d += delta_d
            w += delta_p
            e += delta_p
            s += delta_s
            new_tribe = (d, n, w, e, s, delta_d, delta_p ,delta_s)
            tribes.append(new_tribe)
    return tribes

#print(gen_tribes(l[1]))
            
def raise_wall (wall, to_raise):
    for i in gen_points(to_raise[0][0], to_raise[0][1]):
        wall[i] = max( wall.get(i,0), to_raise[1] )
    

def search(tribes):
    score = 0
    wall = {}
    tribes = gen_tribes(tribes)
    unique_days = sorted([x[0] for x in tribes])
    for day in unique_days :
        to_raises = [] 
        for tribe in tribes:
            to_raise = None
            if tribe[0] == day:
                to_raise = one_run(wall, tribe)
                if to_raise : 
                    to_raises.append( one_run(wall, tribe))
                    score += 1
        for to_raise in to_raises:
            raise_wall(wall, to_raise)
    return score
    
#print(search(l[0]))
         
         
    
with open('c.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        to_write.append(('Case #%s: ' %(i+1)) + str(search(l[i])) + '\n')
    f.writelines(to_write)

    


    
    
    
    
    


