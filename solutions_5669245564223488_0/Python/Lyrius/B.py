# -*- coding: utf-8 -*-
"""
Created on Sun May 11 12:03:20 2014

@author: matthieu
"""
lettres = ['a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'w', 'x', 'c', 'v', 'b', 'n']
import numpy as np

def fact(n):
    if n<2:
        return 1
    else:
        return n*fact(n-1)
        
        
def isvalid(s,let,iden,idenn):
    se = set()
    cur = s[0]
    for car in s:
        if car!=cur:
            if car in se:
                return False
            se.add(cur)
            cur = car
    se.add(cur)
    deb = s[0]
    fin = s[-1]
    if (deb==fin):
        if let[deb][0]:
            return False
        iden[deb]= True
        idenn[deb]+=1
        return True
    else:
        for i in se:
            if i!=deb and i!=fin:
                if let[i][0] or abs(let[i][1])>0 or iden[i]:
                    return False
                let[i][0] = True
    if let[deb][0] or let[fin][0]:
        return False
    if abs(let[deb][1])>2:
        return False
    if let[deb][1]>0:
        let[deb][1] = 2
    elif let[deb][1]<0:
        return False
    else:
        let[deb][1] = -1
    let[deb][2][0] = s     
    if abs(let[fin][1])>2:
        return False
    if let[fin][1]<0:
        let[fin][1] = 2
    elif let[fin][1]>0:
        return False
    else:
        let[fin][1] = 1
    let[fin][2][1] = s
    return True
    
inp  = open("input","r")
out = open("output","w")

T = int(inp.readline())
for case in range(T):
    out.write("Case #"+str(case+1)+": ")
    N = int(inp.readline())
    line = inp.readline().split(" ")
    line[-1] = line[-1].strip()
    let = {}
    for l in lettres:
        let[l] = [False,0,["",""]]
    iden = {}
    idenn = {}
    for l in lettres:
        iden[l] = False
    for l in lettres:
        idenn[l] = 0
    valid = True
    for s in line:
        if not isvalid(s,let,iden,idenn):
            valid = False
            break
    if not valid:
        out.write("0")
        out.write("\n") 
        continue
    nbstring = 0
    mul = []
    for l in lettres:
        if let[l][1]==2:
            if let[l][2][0][0]==let[l][2][1][-1] and let[l][2][0][-1]==let[l][2][1][0]:
                valid = False
                break
            if iden[l]:
                mul.append(fact(idenn[l]))
        elif abs(let[l][1])==1:
            nbstring+=1
            if iden[l]:
                mul.append(fact(idenn[l]))
        elif iden[l]:
            nbstring+=2
            mul.append(fact(idenn[l]))
    if not valid:
        out.write("0")
        out.write("\n")
        continue
    res = fact(nbstring/2)%1000000007
    for i in mul:
        res *=i %1000000007
    out.write(str(res))
    out.write("\n")


out.close()