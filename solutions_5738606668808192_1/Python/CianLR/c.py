from itertools import count

def get_div(n):
    sqrt_n = n**0.5
    for i in count(2):
        if i > 49:
            break
        if n%i == 0:
            return i
    return None

def check_bases(n):
    b = bin(n)[2:]
    base_list = [0]*9
    for i in xrange(2, 11):
        div = get_div(int(b, i))
        if div == None:
            return None
        else:
            base_list[i-2] = str(div)
    return base_list

T = int(raw_input())

for case in xrange(1, T + 1):
    N, J = [int(x) for x in raw_input().split()]
    print "Case #" + str(case) + ":"
    
    pot_coin = 2**(N-1) - 1
    coins = 0
    while coins < J:
        pot_coin += 2
        divs = check_bases(pot_coin)
        if divs == None:
            continue
        else:
            coins += 1
            print bin(pot_coin)[2:], ' '.join(divs)
