'''
Created on 2013-05-04

@author: maplebaconburgr
'''

INPUT = 'A-large.in';
OUTPUT = 'output.txt';

def osmos(size, others, operations):
  #  if(len(others) > 0):
  #      print size, "\t", others[0], "\t", operations;
    
    if len(others) == 0:
        return operations;
    elif size > others[0]:
        size = size + others[0];
        return osmos(size, others[1:], operations)
    elif size <= 1:
        return operations + len(others);
    else:
        alt = len(others);
        next = others[0];
        tempOps = 0;
        while size <= next:
            size = size*2 - 1;
           # print size, "\t", tempOps+1;
            tempOps = tempOps + 1;
        if tempOps >= alt:
            return operations + alt;
        else:
            possible = osmos(size  + next, others[1:], operations + tempOps);
            return min(possible, operations + alt);
    
    
    return 'FAIL';

def main():
    #open files
    inFile = open(INPUT, 'r');
    outFile = open(OUTPUT, 'w');
    
    T = int(inFile.readline());
    
    for case in range(1, T+1):
        size = int(inFile.readline()[:-1].split(' ')[0]);
        others = inFile.readline()[:-1].split(' ');
        others = [int(x) for x in others];
        result = osmos(size, sorted(others), 0);
        outFile.write('Case #' + str(case) + ': ' + str(result) +  '\n');
       # print 'Case #' + str(case) + ': ', size , others ,  '\n'
        
    #close files
    inFile.close();
    outFile.close();

if __name__ == '__main__':
    main();

    