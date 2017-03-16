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
       [A**2,B**2]."""
       lst = []
       for i in range(A, B+1):
              if is_palin(i) and is_palin(i*i):
                            lst.append(i*i)
       return lst


# preprocess fair and square numbers
A = 1
B = 10**7
fsqnumbers = fairsquare(A,B)

f = open("C-large-1.in", "r")
g = open("C-large-1-ans0.txt", "w")

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
g.close()

