import sys
import fileinput
import math

fin = fileinput.input()
fout = sys.stdout

def is_palindrome(x):
    x_s = str(x)
    return x_s == x_s[::-1]

def palindromes(a, b):
    assert a <= b
    
    a_digits = int(math.floor(math.log10(a))) + 1
    b_digits = int(math.floor(math.log10(b))) + 1
    
    for n_digits in xrange(a_digits, b_digits + 1):
        odd = n_digits % 2 == 1
        
        changing_digits = (n_digits + (1 if odd else 0)) / 2
        for i in xrange(10 ** (changing_digits - 1), 10 ** changing_digits):
            i_s = str(i)
            p = int(i_s + (i_s[-2::-1] if odd else i_s[::-1]))
            
            if p < a:
                #print("skip {0}".format(p))  # XXX
                continue
            elif p > b:
                return
            
            assert is_palindrome(p)  # XXX
            yield p

def solve(A, B):
    #print A, B
    
    a_root = math.ceil(math.sqrt(A))
    b_root = math.floor(math.sqrt(B))
    
    count = 0
    if a_root <= b_root:
        for p in palindromes(a_root, b_root):
            if is_palindrome(p ** 2):
                #print(p**2)  # XXX
                count += 1
    
    return count

def main():
    T = int(fin.readline())
    
    for case_idx in xrange(T):
        A, B = tuple(map(int, fin.readline().split()))
        
        result = solve(A, B)
        
        fout.write("Case #{0}: {1}\n".format(case_idx + 1, result))

if __name__ == "__main__":
    #print((list(palindromes(1, 151))))
    main()
