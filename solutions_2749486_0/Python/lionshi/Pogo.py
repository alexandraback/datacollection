#!/usr/bin/python
# -*- coding: utf-8 -*-

def main():
    in_file = open("B-small-attempt0.in", mode='r')
    out_file = open("B-small-attempt0.out", mode='w')

    lines = in_file.readlines()      
    T = int(lines[0])
    
    for i in xrange(T):
        line = lines[i + 1]
        X = int(line.strip().split(' ')[0])
        Y = int(line.strip().split(' ')[1])
        
        ans = ""

        if X>0:
            for j in range(0, X):
                ans += "WE"
        else:
            for j in range(0, -X):
                ans += "EW"
                
        if Y>0:
            for j in range(0, Y):
                ans += "SN"
        else:
            for j in range(0, -Y):
                ans += "NS"
                
        out_file.write("Case #" + str(i+1) + ": " + ans + "\n") 
        
    in_file.close()
    out_file.close()


if __name__ == '__main__':
    main()
