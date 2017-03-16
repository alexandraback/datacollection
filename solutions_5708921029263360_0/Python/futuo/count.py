from itertools import product, combinations

def violates(combs, j, p, s, k):
    count = [ [ [0] * (p+1) for i in range(j+1) ],
              [ [0] * (s+1) for i in range(j+1) ],
              [ [0] * (s+1) for i in range(p+1) ] ]
    for i in combs:
        count[0][i[0]][i[1]] += 1
        count[1][i[0]][i[2]] += 1
        count[2][i[1]][i[2]] += 1

        if count[0][i[0]][i[1]] > k or count[1][i[0]][i[2]] > k or count[2][i[1]][i[2]] > k:
            return True

    return False

NTC = int(input())

for TC in range(1, NTC+1):

    J,P,S,K = [int(i) for i in raw_input().split(" ") if i != ""]

    possibilities = [i for i in product(range(1,J+1), range(1,P+1), range(1,S+1))];
    n = J * P * S

    found = False
    while( not found ):
        for combo in combinations(possibilities, n):
            if( not violates(combo, J, P , S, K) ):
                print("Case #{0}: {1}".format(TC, n))
                print( "\n".join([" ".join([str(j) for j in i]) for i in combo]) )
                found = True
                break
        n -= 1

