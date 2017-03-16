# python3
def solve():
    a=input()
    fin=''
    fr=''
    for j in list(a):
        if fr > j:
            fin += j
        else:
            fin = j + fin
            fr = j
    
    return fin



T=int(input());
 
for t in range(1,T+1):
    print ("Case #" + str(t) + ": " + solve())
