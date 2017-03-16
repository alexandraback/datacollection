import math

def main():
    inf = open("small.in")
    outf = open("small.out", "w")
    
    nr = long(inf.readline())
    for i, line in enumerate(inf):
        tokens = line.split(" ")
        a = long(tokens[0])
        b = long(tokens[1])
        result = solve(a, b)
        outf.write("Case #%s: %s\n" % (str(i+1), str(result)))
        print "Case #%s: %s\n" % (str(i+1), str(result))
    inf.close()
    outf.close()
        
def solve(a, b):
    start = long(math.floor(math.sqrt(a)) - 1)
    fairsquare = 0
    for i in xrange(start, (b + 1)**2):
        
        if isPalindrome(i):
            square = i**2
            if square < a:
                continue;
            if square <= b:
                if isPalindrome(square):
                    print square
                    fairsquare += 1
                else:
                    pass
            else:
                return fairsquare
        else:
            pass

                 

def isPalindrome(num):
    s = str(num)
    return s == s[::-1]

if __name__ == '__main__':
    main()
    #print solve(121, 121)
    