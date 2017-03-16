# -*- coding: utf-8 -*-
"""
Created on Sat Feb 15 18:33:33 2014

@author: Caasar
"""

from sys import stdin
import numpy as np


T = int(stdin.next())
for t,line in enumerate(stdin,1):
    C,F,X = np.fromstring(line,sep=" ")
    
    n_opt = int(np.floor((F*X-C*(2+F))/(F*C)))
    if n_opt < 0:
        min_time = X/2.0
    else:
        part = np.sum(C/(2.0+F*np.arange(n_opt)))
        min_time1 = part+X/(2.0+n_opt*F)
        min_time2 = part+C/(2.0+n_opt*F)+X/(2.0+(n_opt+1)*F)
        min_time = np.minimum(min_time1,min_time2)
        
    print 'Case #%d: %.7f' % (t,min_time)
    
