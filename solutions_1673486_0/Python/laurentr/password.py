#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import sys

with open('./'+sys.argv[1], 'r+') as f:
    with open('./output.txt', 'w') as fout:

        line = f.readline()
        T = int(line)
        for k in range(T):
            A,B = [int(i) for i in f.readline().split()]
            ps = [float(val) for val in f.readline().split()]
            products = [1.0]
            esperance = [B+2.0]
            back = A
            for p in ps:
                products.append(products[len(products)-1]*p)
            for back in range(A):
                if back:
                    esperance.append((B-A+1.0+2*back)*products[len(products)-1-back] + (B+B-A+2.0+2*back)*(1-products[len(products)-1-back]))
                else:
                    esperance.append((B-A+1.0)*products[len(products)-1] + (B+B-A+2.0)*(1-products[len(products)-1]))
                    
            res = min(esperance)
            print products
            print esperance
            print res 
            fout.write("Case #"+str(k+1)+": "+str(res)+"\n")
        
