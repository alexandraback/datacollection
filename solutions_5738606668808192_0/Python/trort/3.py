prime_list = []
def prepare():
    global prime_list
    for i in range(3, 100, 2):
        prime = True
        for p in prime_list:
            if p*p > i: break
            if i%p == 0:
                prime = False
                break
        if prime: prime_list.append(i)

def dec_2_seq(x):
    ss = []
    while x>0:
        d = x%2
        ss.append(d)
        x = x//2
    ss.reverse()
    return ss
#print dec_2_seq(9)
    
def seq_2_num(s, b):
    x = 0
    for i in s:
        x *= b
        x += int(i)
    return x
#print seq_2_num(dec_2_seq(9),10)
    
def check_prime(num):
    #global prime_list
    if num%2 == 0: return 2
    else:
        for i in prime_list:
            if num%i == 0: return i
            if i**2 > num: break
            
        #if prime_list[-1]**2 < num:
        #    j = prime_list[-1] + 2
        #    while j*j < num and j < 1000:
        #        uu = check_prime(j)
        #        if uu == 1:
        #            prime_list.append(j)
        #            if num%j == 0: return j
        #        j += 2
    return 1

def solver(N, J):
    jamcoins = []
    i = 2**(N-1)+1
    while i <= 2**N-1:
        ss = dec_2_seq(i)
        divs = []
        for base in range(2,11):
            num = seq_2_num(ss,base)
            uu = check_prime(num)
            if uu != 1: divs.append(str(uu))
            else: break
        if len(divs) == 9:
            line = ''.join(str(x) for x in ss) + ' ' + ' '.join(divs)
            jamcoins.append(line)
            if len(jamcoins) >= J: break
        i += 2
    if len(jamcoins) >= J:
        return '\n'.join(jamcoins)
    else: return 'NOT ENOUGH'

t = 1 #int(raw_input())  # read a line with a single integer
prepare()
for i in xrange(1, t + 1):
    n, j = [16, 50] #[int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
    ans = solver(n, j)
    print "Case #{}:\n{}".format(i, ans)