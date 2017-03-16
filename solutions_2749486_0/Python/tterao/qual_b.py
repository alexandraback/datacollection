'''
Created on 2012/04/14

@author: teraotsuyoshi
'''

def check(str):
    x = 0
    y = 0
    l = 1
    for i in str:
        if i == 'N':
            y += l
        elif i == 'S':
            y -= l
        elif i == 'E':
            x += l
        elif i == 'W':
            x -= l
        l += 1
    
    return (x, y)

        
if __name__ == '__main__':
    lines = open("B-small-attempt1.in").readlines()
    T = int(lines[0])
    ln = 1
    for i in range(1, T+1):
        (X,Y) = lines[i].split()
        X = int(X)
        Y = int(Y)
        
        str = ""

        s1 = ""        
        if X > 0:
            s1 = "EW"
        elif X < 0 :
            s1 = "WE"

        if X != 0:        
            str += s1 * (abs(X)-1) + s1[0]

        s1 = ""
        if Y > 0:
            s1 = "SN"
        else :
            s1 = "NS"

        if Y != 0:
            str += s1 * abs(Y)
        
        if check(str) != (X,Y) or len(str) > 500:
            print "ERROR", (X,Y), check(str)

        print "Case #%d:"%i, str
                
        
