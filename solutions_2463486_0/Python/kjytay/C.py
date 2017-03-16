from math import floor
from math import ceil

def is_palin(number):
       """Returns True if number is a palindrome. Else returns False."""
       if number % 10 == 0:
              return False
       temp = str(number)
       return temp == temp[::-1]

def fairsquare(A,B):
       """Returns a list of fair and square numbers in the closed interval
       [A,B]."""
       lst = []
       lower = int(floor(A**0.5))
       upper = int(ceil(B**0.5)) + 1

       for i in range(lower, upper):
              if is_palin(i) and is_palin(i*i):
                     if A <= i*i and i*i <= B:
                            lst.append(i*i)

       return lst


# preprocess fair and square numbers
A = 1
B = 1000
fsqnumbers = fairsquare(A,B)

f = open("C-small-attempt0.in", "r")
g = open("C-small-ans0.txt", "w")

T = int(f.readline()) # no of test cases
k = 0
while k < T:
    # get A & B
    [A, B] = f.readline().strip().split(" ")
    A = int(A)
    B = int(B)

    temp = [i for i in fsqnumbers if (A<=i and i<=B)]

    #print "Case #" + str(k+1) + ": " + str(len(temp))
    g.write("Case #" + str(k+1) + ": " + str(len(temp)) + "\n")

    # move on to the next case
    k += 1

f.close()
#g.close()

