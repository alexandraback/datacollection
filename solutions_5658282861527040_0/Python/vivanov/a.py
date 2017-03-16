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


fn = 'treasure.in'
fn = '/Users/vivanov/Downloads/A-large.in'
fn = '/Users/vivanov/Downloads/B-small-attempt0.in'

with open(fn) as f:
    lines = f.read().splitlines()[1:]
    l = []
    i = 0
    while i < len(lines):
        a, b, k = [int(k) for k in lines[i].split(' ')]
        i += 1
        l.append({'a' : a, 'b' : b, 'k' : k})


import copy

pass

def search(state):
    a = state['a']
    b = state['b']
    k = state['k']
    counter = 0
    for i in range(a):
        for j in range(b):
            if (i & j) < k:
                counter += 1
    return counter


#r = remove_all_pairs(l[1])
#res = solvable(r)
#c = calc_coordinates(l[2])
#ans = search(l[4])


pass


with open('treasure.out', 'w') as f :
    to_write = []
    for i in range(len(l)):
        res = search(l[i])
        to_write.append('Case #%s: %s \n' %((i+1), res))
    f.writelines(to_write)

