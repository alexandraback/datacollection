f = open('Google Fair and Square Small.in','r')
g = open('Google Fair and Square Small.out','w')

def Google_print(filename,answers):
    for i in range(len(answers)):
        filename.write("Case #%s: %s\n" % (str(i+1),answers[i]))
        print "Case #%s: %s" % (str(i+1),answers[i])
    return

def is_palindrome(n):
    s = str(n)
    for i in range(len(s)/2):
        if s[i] != s[-1-i]:
            return False
    return True

fairandsquare = []

for i in range(1,32):
    if is_palindrome(i) and is_palindrome(i**2):
        fairandsquare.append(i**2)

def subrange(a,x,y):
    return len([p for p in a if y >= p >= x])

cases = int(f.readline())
answer = []
for i in range(cases):
    x,y = f.readline().rstrip().split(' ')
    x = int(x)
    y = int(y)
    answer.append(subrange(fairandsquare,x,y))
Google_print(g,answer)
g.close()
f.close()





    
