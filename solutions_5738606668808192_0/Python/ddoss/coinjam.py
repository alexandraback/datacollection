import sys
import random

def main():
    num_cases = int(sys.stdin.readline())
    cases = [sys.stdin.readline().strip() for i in range(num_cases)]
    memo_dict = {}
    for i in range(num_cases):
        print("Case #"+str(i+1)+":"+str(solve(cases[i])))

def solve(case):
    N,J = int(case.split(' ')[0]), int(case.split(' ')[1])
    coins = set()
    while len(coins)<J:
        test_coin = randcoin(N)
        coin_string = test_coin
        is_prime = False
        for base in range(2,11):
            value = sum([base**i if test_coin[-i-1]=='1' else 0 for i in range(N)])
            if check_prime(value):
                is_prime = True
                break
            else:
                coin_string+=" "+str(get_factor(value))
        if is_prime:
            continue
        else:
            coins.add(coin_string)
    return ''.join(['\n'+coin for coin in coins])

def check_prime(num):
    return num%2!=0 and (pow(2, num-1, num)==1)

def get_factor(num):
    for i in range(2, int(num**0.5)+1):
        if num%i==0:
            return i
    else:
        return -1




def randcoin(length):
    return '1'+''.join(['0' if random.random()<0.5 else '1' for i in range(1,length-1)])+'1'

if __name__=='__main__':
    main()
