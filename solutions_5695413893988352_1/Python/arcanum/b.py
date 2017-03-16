from math import *

def rl(l): return range(len(l))



f = open("b.out", mode='w')

T = int(input())

C = ""
J = ""

def getans(a1, a2):
    
    a1 = (int(a1[0]), int(a1[1]))
    a2 = (int(a2[0]), int(a2[1]))
    
    d1 = abs(a1[1] - a1[0]) 
    d2 = abs(a2[1] - a2[0])

    # minimize abs diff
    if d1 < d2:
        return a1
    elif d2 < d1:
        return a2
    else: # min c score
        if a1[0] < a2[0]:
            return a1
        elif a2[0] < a1[0]:
            return a2
        else: # min j score
            if a1[1] < a2[1]:
                return a1
            elif a2[1] < a1[1]:
                return a2
            return a2 # equal

def go(ind, N, c, j):
    if ind >= N:
        return (c, j)

    if c[ind] == "?" and j[ind] == "?":
        # 90 or 00 or 09

        if ind == 0 or int(c[:ind]) == int(j[:ind]):
            
            a1 = go (ind+1, N, c[:ind]+"0"+c[ind+1:], j[:ind]+"0"+j[ind+1:]) # REC
            a2 = go (ind+1, N, c[:ind]+"0"+c[ind+1:], j[:ind]+"1"+j[ind+1:]) # REC
            a3 = go (ind+1, N, c[:ind]+"1"+c[ind+1:], j[:ind]+"0"+j[ind+1:]) # REC
            a = getans(a1, a2)
            a = getans(a, a3)
            return a
        
        if int(c[:ind]) > int(j[:ind]):
            a1 = go (ind+1, N, c[:ind]+"0"+c[ind+1:], j[:ind]+"9"+j[ind+1:]) # REC
            a2 = go (ind+1, N, c[:ind]+"0"+c[ind+1:], j[:ind]+"0"+j[ind+1:]) # REC
            
            return getans(a1, a2)# need this block?
         
                    
        elif int(c[:ind]) < int(j[:ind]):
            a1 = go (ind+1, N, c[:ind]+"9"+c[ind+1:], j[:ind]+"0"+j[ind+1:]) # REC
            a2 = go (ind+1, N, c[:ind]+"0"+c[ind+1:], j[:ind]+"0"+j[ind+1:]) # REC
            return getans(a1, a2)

    elif c[ind] == "?":
        # TIMING COULD BE CHECKING 3^n!
        # try above and below and equal to j[ind]

        
            
#            return go (ind+1, N, c[:ind]+"0"+c[ind+1:], j) # REC
            

        if ind == 0 or int(j[:ind]) == int(c[:ind]):

            odigit = int(j[ind])
            lind = max(0, odigit-1)
            hind = min(9, odigit+1) # misnomer; low digit and high digit

            '''experimental; works on c and j'''
            '''
            if ind+1 < N and (c[ind+1]+j[ind+1]).count("?") == 1:
                lind = odigit
                hind = odigit
            '''

            aprev = None
            anew = None

            for i in range(lind, hind+1): # correcting at source!
                anew = go (ind+1, N, c[:ind]+str(i)+c[ind+1:], j) # REC
                if aprev:
                    anew = getans(anew, aprev)

                aprev = anew
            
            return anew
        
        elif int(c[:ind]) > int(j[:ind]):
            
            return go (ind+1, N, c[:ind]+"0"+c[ind+1:], j) 

        elif int(c[:ind]) < int(j[:ind]):

            return go (ind+1, N, c[:ind]+"9"+c[ind+1:], j) 


        

    elif j[ind] == "?":

        if ind == 0 or int(j[:ind]) == int(c[:ind]):

          
            
            odigit = int(c[ind])
            lind = max(0, odigit-1)
            hind = min(9, odigit+1)


            '''experimental; works on c and j'''
            
            '''
            if ind+1 < N and (c[ind+1]+j[ind+1]).count("?") == 1: # this might not work for same placement, eg ?? and 34, or does it?
                lind = odigit
                hind = odigit
            '''
            


            aprev = None
            anew = None

            for i in range(lind, hind+1): # inclusive!
                anew = go (ind+1, N, c, j[:ind]+str(i)+j[ind+1:]) # REC
                if aprev:
                    anew = getans(anew, aprev)

                aprev = anew
            
            return anew

        elif int(j[:ind]) > int(c[:ind]):
            
                return go (ind+1, N, c, j[:ind]+"0"+j[ind+1:]) 

        elif int(j[:ind]) < int(c[:ind]):

                return go (ind+1, N, c, j[:ind]+"9"+j[ind+1:]) 
        
    else: # both have digits here
        return go(ind+1, N, c, j)


def leftpad(s, length):
    return "0"*(length - len(s)) + s

for nt in range(1, T+1):
    C, J = list(map(str, input().split()))
    N = len(C)

    anst = go(0, N, C, J)
    
    #print(anst)
    ans = leftpad(str(anst[0]), N)+" "+leftpad(str(anst[1]), N) # Gets longer

    #ans = 

    
    towrite = "Case #"+str(nt)+": "+str(ans)+'\n'
    f.write(towrite)
    print(towrite, end="")
    
f.close()

'''
11
?????????????????? ??????????????????
??134????????????? ???????2??????3???
412343214213432144 ??????????????????
123?023??23?0?3?2? 1239923092388?9??9
?1?2?3?4?5?6?7?8?9 1?2?3?4?5?6?7?8?9?
?1?2?3 1?2?30
?3?4?5??9? 3?4?5??6?0
23?023?9? 237923409
237923409 23?023?9?
?99 ??0
2?99 2??0

for i in 3**18


# reverse c and j and try
[all cases]


123902399239093929
123902399239093929
123992309238809009
123992309238809009
case 4 ends in 3929, 9009
case 7 both 3344550690
case 8 is 237023090, 237923409
099 100


4
1? 2?
?2? ??3
? ?
?5 ?0
'''
