import math

def p_mat(mat):
    for row in mat:
        print("".join(map(str, row)))

def poss(b,m,case): 
    mat = [[0]*b for _ in range(b)]
    mat[0][b-1]=1
    m-=1
    if m != 0:
        repr = "{0:b}".format(m)
        for i in range(1,len(repr)+1):
            mat[i][b-1] = 1
            for j in range(1,i):
                mat[i][j] = 1
            if repr[-i] == "1":
                mat[0][i] = 1

    print("Case #%d: %s" % (case + 1, "POSSIBLE"))
    p_mat(mat)
     
def imposs(case):
    print("Case #%d: %s" % (case + 1, "IMPOSSIBLE"))  

def main():
    for _ in range(int(input())):
        b,m = map(int, input().split())
        if (m==1):
            poss(b,m,_)
            continue 
        bits = int(math.floor(math.log(m-1, 2))) + 1
        if bits + 2 > b:
            imposs(_)
        else:
            poss(b,m,_)
        

main()
