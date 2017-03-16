
import math;

def find_divisor(x):
    i = 2;
    limit = int(math.sqrt(x)) + 1;
    while i < limit:
        if ((x - (x / i)*i) == 0) and (x % i == 0):
            return i
        i += 1;
    return -1

def jamcoin_proof(s):
    proof = []
    for i in range(2, 11):
        x = int(s, i)
        div = find_divisor(x);
        if div != -1:
            proof.append(div);

    if len(proof) == 9:
        return proof

    return None

def divisible_3(dec_str):
    total = 0;
    for i in range(len(dec_str)):
        total += int(dec_str[i]);

    if total % 3 != 0:
        return False

    return True

def divisible_5(dec_str):
    if (dec_str[-1] == '5') or (dec_str[-1] == '0'):
        return True

    return False

def divisible_7(dec_str):
    result = int(dec_str[:-1]) - (int(dec_str[-1]) * 2);

    if abs(result) < 10:
        if result in (7, -7, 0):
            return True
        else:
            return False
    else:
        return divisible_7(str(abs(result)))


def divisible(s):
    for i in range(2, 11, 2):
        x = int(s, i)
        dec_str = str(x)
        if divisible_3(dec_str):
            continue
        elif divisible_5(dec_str):
            continue
        elif divisible_7(dec_str):
            continue
        else:
            return False
        
    return True


def easy_proof(s):
    proof = []
    total_1 = 0
    # ensure number is even in odd-base numbers
    for i in range(len(s)):
        if s[i] == '1':
            total_1 += 1;

    if total_1 % 2 != 0:
        return None

    # only use numbers that are divisible by 3 in even base numbers
    if divisible(s):
        return jamcoin_proof(s)
    else:
        return None


def abc(N, J):
    
    i = pow(2, N - 1) + 1;
    limit = pow(2, N);
    while i < limit:
        i += 2;
        n = bin(i)[2:]
        proof = easy_proof(n);
        if proof != None:
            print n, ' '.join(map(str, proof));
            J -= 1
        if J == 0:
            break;

if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline());
        for t in range(T):
            N, J = f.readline().split(' ');
            print 'Case #{}:'.format(t+1)
            abc(int(N), int(J))
