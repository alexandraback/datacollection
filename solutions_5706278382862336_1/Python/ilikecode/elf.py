from multiprocessing import Pool
import os
import fractions

def solvePuzzle(numerator, denominator):
    numerator=int(numerator)
    denominator=int(denominator)
    gcd = fractions.gcd(numerator, denominator)
    numerator=numerator//gcd
    denominator=denominator//gcd
    if testTwo(denominator):
        return "impossible"
    i=0
    while numerator<denominator:
        numerator*=2
        i+=1
    return str(i)

def testTwo(num):
    return num&(num-1)

input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
currentLine=1
with open("output", "a") as outputfile:
    pool = Pool(processes=6)
    results = {}
    for num in range(0,int(lines[0])):
        fraction=lines[num+1].split("/")
        results[num]= pool.apply_async(solvePuzzle, [fraction[0],fraction[1]])
    for num in range(0,int(lines[0])):
        outputfile.write("Case #"+str(num+1)+": "+results[num].get()+"\n")
