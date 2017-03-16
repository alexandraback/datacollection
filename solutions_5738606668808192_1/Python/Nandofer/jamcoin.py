'''
Created on Apr 8, 2016

@author: flmendez
Jamcoin
'''
import argparse
import sys
import math


def get_binary(num):
    curr_num = num
    expansion =list()
    while curr_num > 0:
        expansion.append(curr_num%2)
        curr_num /= 2
    expansion.reverse()
    return ''.join([str(x) for x in expansion])

def get_num(expression, base=2):
    expr = list(str(expression))
    outnum = 1
    for idx in range(len(expr)-1):
        outnum = outnum*base+ int(expr[idx+1])
    return outnum

def get_in_base(newbase, binary_expr):
    return get_num( get_binary(binary_expr), newbase)


def coin(line, prime_list):
    coinlen, coinnum = [int(x) for x in line.split()]
    outcoinjam = list()
    binary_number ='1'
    for _ in range(coinlen-2):
        binary_number += '0'
    binary_number += '1'
    current_numbers= [get_num(binary_number)]
    for i in range(3,11):
        current_numbers.append(get_in_base(i,current_numbers[0]))

    while len(outcoinjam)<coinnum:
        divisors =dict()
        divfound = dict()
        for i in range(2,11):
            idx_div = 0
            divfound[i] = False
            while not divfound[i] and idx_div < len(prime_list):
                testdivisor= prime_list[idx_div]
                if current_numbers[i-2]%testdivisor ==0:
                    divisors[i] = testdivisor
                    divfound[i] = True
                idx_div +=1 

        if len(divisors.keys()) ==9:
            outcoinjam.append([get_binary(current_numbers[0])])
            for i in range(2,11):
                outcoinjam[-1] += [str(divisors[i])]
            outcoinjam[-1] = ' '.join(outcoinjam[-1])    
        current_numbers[0] += 2
        for i in range(3,11):
            current_numbers[i-2] = get_in_base(i,current_numbers[0])
    return '\n'.join(outcoinjam)    
        
def get_prime_list (max_digits):
    cutoff =10
    for _ in range(max_digits):
        cutoff *=10 
    prime_list = [2,3,5,7,11,13,17,19,23,29,31]
    current_val = 33
    while  current_val <= cutoff:
        div_found = False
        indprim = 1
        while not div_found and prime_list[indprim]*prime_list[indprim] <=  current_val:
            if current_val%prime_list[indprim]==0:
                div_found = True
            indprim += 1
        if not div_found:
            prime_list.append(current_val)
        current_val += 4

        div_found = False
        indprim = 1
        while not div_found and prime_list[indprim]*prime_list[indprim] <=  current_val:
            if current_val%prime_list[indprim]==0:
                div_found = True
            indprim += 1
        if not div_found:
            prime_list.append(current_val)
        current_val += 2
    return prime_list

parser = argparse.ArgumentParser(description='''Jamcoin''',  epilog='')
parser.add_argument('input',  help='input file', )
parser.add_argument('output', help='output file')
args = parser.parse_args()

inFile = open (args.input)
outFile = open (args.output, 'w')

line = inFile.readline()
line= line.strip()
ncases = int(line)
for case in range(1, ncases+1):
    line = inFile.readline()
    line = line.strip()
    prime_list = get_prime_list(4)
    sol = coin(line, prime_list)
    outFile.write('Case #'+str(case)+":\n"+str(sol)+"\n")
