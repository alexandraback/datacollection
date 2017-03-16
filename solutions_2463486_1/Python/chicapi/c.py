l1 = 1000
l2 = 10**14
l3 = 10**100

def is_palindrome(a):
    s = str(a)
    lens = len(s)
    for i in range(0, lens/2+1):
        if (s[i] != s[-i-1]):
            return False
    return True

count = 0
i = 1
while i < int(l3**0.5) + 1:
    if is_palindrome(i**2) and is_palindrome(i):
        count+=1
        print '%d /* %d */, ' % (i**2, i) ,
        if count > 0 and count % 10 == 0:
            print
    i += 1
print
print count


