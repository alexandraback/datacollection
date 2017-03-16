#!/usr/bin/python
# -*- coding: utf-8 -*-

def main():
    in_file = open("A-small-attempt0.in", mode='r')
    out_file = open("A-small-attempt0.out", mode='w')

    lines = in_file.readlines()      
    T = int(lines[0])
    
    vowels = ['a', 'e', 'i', 'o', 'u']
    
    for i in xrange(T):
        line = lines[i + 1]
        name = line.strip().split(' ')[0]
        L = int(line.strip().split(' ')[1])
        
        ccount = 0
        last = 0
        n = 0
        
        for j in range(0, len(name)):
            if name[j] in vowels:
                if ccount >= L:
                    last = j-L+1
                ccount = 0
            else:
                ccount += 1
                
            if ccount >= L:
                n += (j+1-L-last+1) * (len(name)-j)
                last = j+1-L+1                
                
        out_file.write("Case #" + str(i+1) + ": " + str(n) + "\n") 
        
    in_file.close()
    out_file.close()


if __name__ == '__main__':
    main()
