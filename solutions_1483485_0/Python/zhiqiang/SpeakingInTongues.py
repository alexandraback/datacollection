'''
Created on 2012-4-14

@author: zhiqiang
'''
import sys

def loadData(file):
    cases = []
    with open(file) as fin:
        N = int(fin.readline())
        for line in fin:
            cases.append(line.strip())
    return cases

def output(res,file = sys.stdout):
    for i in range(len(res)):
        print('Case #{}:'.format(i+1), res[i], file=file)

def main(cases):
    codebook={' ':' ',
              'a': 'y',             
              'b': 'h',
              'c': 'e',
              'd': 's',
              'e': 'o',
              'f': 'c',
              'g': 'v',
              'h': 'x',
              'i': 'd',
              'j': 'u',
              'k': 'i',
              'l': 'g',
              'm': 'l',
              'n': 'b',
              'o': 'k',
              'p': 'r',
              'q': 'z',
              'r': 't',
              's': 'n',
              't': 'w',
              'u': 'j',
              'v': 'p',
              'w': 'f',
              'x': 'm',
              'y': 'a',
              'z': 'q'}
    res=[]
    for case in cases:
        res.append(''.join([codebook[case[i]] for i in range(len(case))]))
    return res
        
if __name__ == '__main__':
    cases = loadData('A-small-attempt0.in')
    res = main(cases)
    output(res)