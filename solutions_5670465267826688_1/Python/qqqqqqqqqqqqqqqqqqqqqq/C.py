char_to_int = { "i":2, "j":3, "k":4 }

matrix = [ [1, 2, 3, 4],\
           [2, -1, 4, -3],\
           [3, -4, -1, 2],\
           [4, 3, -2, -1] ]
           
def mult(a, b):
    return matrix[abs(a)-1][abs(b)-1] * a * b // abs(a*b)
    
def power(a,b):
    if b == 1:
        return a
    if b % 2 == 0:
        v = power(a, b//2)
        return mult(v,v)
    else:
        return mult(a, power(a, b-1))

for T in range(int(input())):
    L, X = map(int, input().split())
    S = input()
    S = [(lambda x: char_to_int[x])(c) for c in S]
    v = 1
    for i in S:
        v = mult(v, i)
    end = v
    S = S * min(X, 10)
    seen = {}
    v = 1
    stage = 1
    for j in range(X):
        if stage == 3:
            break
        if v in seen:
            break
        seen[v] = True
        for i in S:
            v = mult(v, i)
            #print(v, stage)
            if stage == 1:
                if v == 2:
                    stage = 2
            elif stage == 2:
                if v == 4:
                    stage = 3
    
    if stage == 3 and power(end, X) == -1:
        result = "YES"
    else:
        result = "NO"
    print ("Case #%d: %s" % (T+1, result))
    