import math

def isprime(number, base):
    i = 2
    #print(number, i)
    while i*i <= 1000:
        #print(i*i)
        #if base == 8 and i == 32833:
        #    print("8", i)
        if int(number,base) % i == 0:

            return i
        i += 1
    return True

def isprimeallbases(number):
    output = ""
    for z in range(2, 10 + 1):
        question = isprime(number, z)
        if question != True:
            output += " " + str(question)
        else:
            # number is prime in this base
            output = None
            break
    return output



t = int(input())
for i in range(1, t + 1):
    input_line = raw_input()

    N, J = input_line.split(" ")
    N = int(N)
    J = int(J)
    print("Case #{}: ".format(i))


    number = "1" + "0" * (N-2) + "1"

    #print(int(number,2))
    #print(int(number,3))



    j = 0

    while j != J:
        output = isprimeallbases(number)
        if(output):
            print("{}{}".format(number, output ))
            j += 1

        int_number = int(number,2)
        #print(int_number)
        int_number += 2
        number = "{0:b}".format(int_number)


    #print(int("100101", 8))


















