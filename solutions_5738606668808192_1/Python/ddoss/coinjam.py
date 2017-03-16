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
    coin_mid='0'*(N-2)
    while len(coins)<J and coin_mid!='MAX':
        test_coin = '1'+coin_mid+'1'
        coin_string = test_coin
        is_prime = False
        for base in range(2,11):
            value = sum([base**i if test_coin[-i-1]=='1' else 0 for i in range(N)])
            factor = get_factor(value)
            if factor==-1:
                is_prime = True
                break
            else:
                coin_string+=" "+str(get_factor(value))
        if not is_prime:
            coins.add(coin_string)
        coin_mid=incr(coin_mid)
    if coin_mid=='MAX':
        print 'FAILED'

    return ''.join(['\n'+coin for coin in coins])

def incr(num):
    for i in range(len(num)):
        if num[-i-1]=='0':
            return num[0:-i-1]+'1'+'0'*i
    return 'MAX'

def check_prime(num):
    return num%2!=0 and (pow(2, num-1, num)==1)

def get_factor(num):
    i = 2
    while i<1000:
        if num%i==0:
            return i
        i+=1
    return -1




def randcoin(length):
    return '1'+''.join(['0' if random.random()<0.5 else '1' for i in range(1,length-1)])+'1'

if __name__=='__main__':
    main()
