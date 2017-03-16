def isPalindrome(n):
    return list(str(n)) == list(reversed(str(n)))

def squareIsFairAndSquare(n):
    return isPalindrome(n) and isPalindrome(n*n)

#for n in range(1, 10000000):
    #if squareIsFairAndSquare(n):
        #print(n)

# all palindromes with 'k' digits
def palindromes(k):
    if k%2 == 0:
        h = k//2
        for x in range(10**h):
            if x%10 != 0:
                right = ['0']*(h-len(str(x))) + list(str(x))
                yield int(''.join(list(reversed(right)) + right))

    elif k == 1:
        for i in range(1, 10): 
            yield i
    else: 
        for middle in range(0, 10):
            h = (k-1)//2
            for x in range(10**h):
                right = ['0']*(h-len(str(x))) + list(str(x))
                if x%10 != 0:
                    yield int(''.join(list(reversed(right)) + [str(middle)] +  right))

fairAndSquare = set()
for k in range(1, 9):
    for p in palindromes(k):
        if isPalindrome(p*p):
            fairAndSquare.add(p*p)

T = int(input())
for test in range(T):
    a, b = map(int, input().split(' '))
    ans = set()
    for fas in fairAndSquare:
        if a <= fas <= b:
            ans.add(fas)
    print( "Case #{}: {}".format(test+1, len(ans)))
