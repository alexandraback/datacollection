def check(number):
    square = str(number * number)
    return square == square[::-1]

def consistent(e):
    digits = [int(x) for x in e[::-1] + e[1:]]
    return sum(x * x for x in digits) <= 9


#small fair & square numbers
fairAndSquareRoot = [1, 2, 3, 11, 22]

#for numbers greater than 99, last digit is either 1 or 2
possibleTail = ['1', '2']
#2i -1 or 2i is the length of the square root
for i in range(2, 26):
    possibleTail = [digit + tail
          for tail in possibleTail
          for digit in ['0','1','2'] # digits greater than 2 cannot appear
          if consistent(digit + tail)]
    candidates = [int(n[::-1] + n[1:]) for n in possibleTail] #square root odd length
    candidates += [int(n[::-1] + n) for n in possibleTail]    #square root even length
    fairAndSquareRoot += [number for number in candidates if check(number)]
    #print(i, len(fairAndSquareRoot), len(possibleTail))


fin = open('C-small-attempt0.in', 'r') 
T = int(fin.readline().split()[0])
fout = open('C-small-attempt0.out', 'w')
for caseNo in range(1, T + 1):
    A, B = [int(x) for x in fin.readline().rstrip().split()]
    answer = [x for x in fairAndSquareRoot if A <= x * x <= B]
    fout.write('Case #' + str(caseNo) + ': ' + str(len(answer)) + '\n')

fin.close()
fout.close()

