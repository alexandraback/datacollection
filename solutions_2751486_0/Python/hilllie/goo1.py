'''
Created on 14 Apr 2013

@author: david
'''

def val(st, n):
    n = int(n)
    #print n
    #print st
    l = len(st)
    ctr = 0
    
    for i in range(l+1): 
        for j in range(i,l+1):
            currst = st[i:j]
            flag = True
            currctr = 0
            for letter in currst:
                if letter not in "aeiou":
                    currctr+=1
                    if currctr == n:
                        ctr+=1
                        break
                else:
                    currctr=0
    
                    
                
    return str(ctr)

def goo1():
    res = ""
    counter = 1
    with open("goo1.in") as f:
        content = f.readlines()
    for line in content[1:]:
        sp = line.strip().split(" ")
        res += "Case #"+str(counter)+ ": "+val(sp[0], sp[1]) +"\n"
        counter+=1
    print res
    

if __name__ == '__main__':
    goo1()