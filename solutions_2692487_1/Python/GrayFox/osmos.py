'''
Created on May 4, 2013

@author: grayfox
'''

import random

def generate_input(max_A, max_N, max_size):
    T = 100
    cases = []
    for i in range(T):
        case = []
        N = max_N
        case.append((random.randint(1,max_A),N))
        motes = []
        for j in range(N):
            motes.append(random.randint(1,max_size))
        case.append(motes)
        cases.append(tuple(case))
    return (T,max_A,max_N,cases)

def solve(motes,i,a):
    while i<len(motes):
        if motes[i]<a:
            a+=motes[i]
            i+=1
        else:
            break
    if i == len(motes):
        return 0
    opt1 = len(motes)-i
    if a == 1:
        return opt1
    opt2 = 0
    while motes[i]>=a:
        opt2 +=1
        a += (a-1)
    opt2 += solve(motes,i,a)
    return min(opt1,opt2)

def parse_input(filename):
    f = open(filename)
    T = int(f.readline())
    cases = []
    for i in range(T):
        params = [int(j) for j in f.readline().split()]
        motes = [int(j) for j in f.readline().split()]
        cases.append((params,motes))
    return cases
            
    
if __name__ == '__main__':
    #cases = generate_input(1000000, 1000, 1000000)[3]
    cases = parse_input("testcase")
    f = open("output","w")
    i = 1
    for case in cases:
        a = case[0][0]
        n = case[0][1]
        motes = sorted(case[1])
        ops = solve(motes,0,a)
        f.write("Case #%s: %s\n" % (i,ops))
        i += 1
        