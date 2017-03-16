import sys
import time



    
for tc in range(int(input())):
    p = list(input())

    n = len(p)
    i = 1
    trans = 0
 
    while i < n:

        if p[i] != p[i-1]:
            trans +=1

        i = i+1

    if p[n-1] != '+':
        trans += 1

    print("Case #"+str(tc+1)+": " +str(trans))

#remove black => nb of transiitons -1
