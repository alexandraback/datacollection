import math
prime_dict = {}
divisor_dict = {}
def isPrime(num):
    if num in prime_dict:
        return True
    if num % 2 == 0:
        divisor_dict[num] = 2
        return False
    d = 3
    while(d <= math.sqrt(num) + 1):
        if num % d == 0:
            divisor_dict[num] = d
            return False
        d += 2
    prime_dict[num] = True
    return True

def is_prime_in_any_base(num):
    for i in range(2, 11):
        if isPrime(int(str(num), i)):
            return True
    return False

def increment_bin(n):
    n = str(bin(int(n, 2) + 1))
    return n[n.index('b') + 1 :]

def get_divisor_in_all_base(num):
    out = []
    for i in range(2, 11):
        out.append(divisor_dict[int(num, i)])
    return out

def jam_coin(l, n):
    return_list = []
    current = "1"
    if(l > 1):
        current = "1" + "0" * (l -2) + "1"
    while len(return_list) < n and len(current) == l:
        if not is_prime_in_any_base(current):
            return_list.append(current)
        current = increment_bin(current)
        if current[-1:] == "0":
            current = increment_bin(current)
    return return_list

cases = int(raw_input())
for case in range(cases):
    line_in = raw_input().strip().split(" ")
    l = int(line_in[0])
    n = int(line_in[1])
    out = jam_coin(l, n)
    print "Case #" + str(case+1) + ": "
    for num in out:
        divisors = get_divisor_in_all_base(num)
        divisors = map(str, divisors)
        print num + " " + " ".join(divisors)
