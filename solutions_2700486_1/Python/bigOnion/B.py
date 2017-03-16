directory = 'C:/users/hai/my projects/google code jam/2013/round1b/B/'


from decimal import Decimal
from fractions import Fraction


def factorial (n):
    s = 1
    for i in range(1,n+1):
        s *= i
    return s

def binomial (n,k):
    if k > n:
        print ('oh no!')
        return 0
    return factorial (n) // (factorial(k)*factorial(n-k))

def solve (f_in, f_out):
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        #print ('\ntestcase = ' , testcase)
        N, X, Y = [int(x) for x in f_in.readline().split()]
        result = calc (N,X,Y)
        f_out.write('Case #' + str(testcase) + ': ' + str(result) + '\n')


def calc (N, X, Y, debug=0):
    if debug:
        print ('N = ', N)
        print ('X,Y = ',X,Y)
    
    if Y < 0:
        return 0
    if (X+Y) % 2 == 1:
        return 0

    l = 1
    while sum(range(1,l+1)) <= N:
        l += 2

    if debug:
        print ('l = ',l)
    
    if abs(X) + abs(Y) +1 < l:
        return 1

    if abs(X) + abs(Y)  + 1 > l :
        return 0

    if X == 0:
        if sum(range(1,Y+2)) <= N:
            return 1
        else:
            return 0
        
    n0 = N - sum(range(1,l-1))
    if debug:
        print ('n0 = ',n0)
##    if n0 > (l-1):
##        print ('kuku1')
##        leftovers = n0 - 2 * (n0 - (l-1))
##        height = Y - (n0 - (l-1))
##    else:
##        print ('kuku2')
##        leftovers = n0
##        height = Y

##    print ('leftovers = ', leftovers)
##    print ('height =', height)
##    s = 0
##    for i in range(height+1, leftovers+1):
##        s += binomial (leftovers, i)

##    print ('s = ',s)

    if (Y+1) + (l-1) <= n0:
        if debug:
            print ('here')
        return 1

    if debug:
        print ('kuku')
    s = 0
    for i in range(Y+1, n0+1):
        s += binomial (n0, i)
    if debug:
        print ('s = ',s)
    
    #return  make_decimal_string(Fraction(s, 2**n0))
    return  float(Fraction(s, 2**n0))
    #return Decimal(s) / Decimal(2**leftovers)



def make_decimal_string(frac):
    nom_high = 999999999
    nom_low = 1

    while nom_high - nom_low > 1:
        #print (nom_high, nom_low)
        nom_mid = (nom_high + nom_low)//2
        if Fraction(nom_mid, 1000000000) > frac:
            nom_high = nom_mid
        else:
            nom_low = nom_mid

    assert Fraction (nom_mid,1000000000) - frac < Fraction(1,1000000)

    return '0.' + ('0'*10 + str(nom_mid))[-9:]

        
        


def main_run():
    import os
    import time
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_mtime, x) for x in filenames]
    chosen_filename =  sorted(l1)[-1][1][:-3]

    print ('Directory : ', directory)
    print ('Chosen Filename : ',chosen_filename)
    print()
    print ('Start : ', time.ctime())
    print()
    
    f_in = open(directory+chosen_filename+'.in')
    f_out = open(directory+chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()

    print ()
    print ('End : ', time.ctime())


main_run()
