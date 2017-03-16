"""
Jonathan Simowitz

Google Code Jam 2012
Round 1B
"""

import os

def gen_sum(num, pool, current, sums):
    if num == 0:
        total = sum(current)
        test = sums.get(total)
        if test:
            if set(test) != set(current):
                return True, test, current
            else:
                return False, None, None
        else:
            sums[total] = current
            return False, None, None
    else:
        for number in pool:
            new_current = current[:]
            new_pool = pool[:]
            new_current.append(number)
            new_pool.remove(number)
            ret, t, c = gen_sum(num-1, new_pool, new_current, sums)
            if ret:
                return True, t, c
        return False, None, None

def stringinize(values):
    val = ""
    for number in values:
        val += str(number) + " "
    return val.strip()

"""
Funciton responsible for applying the algorithm
on the test data and returning the output
"""
def process(data):
    values = data.split()
    values = values[1:]
    for i in range(len(values)):
        values[i] = int(values[i])
    
    #start with 1 number, then 2, then 3...etc
    sums = {}
    for i in range(1,len(values)+1):
        test, t, c = gen_sum(i, values, [], sums)
        if test:
            return stringinize(t) + "\n" + stringinize(c)
    return "Impossible"

"""
Main function initializes files, iterates through
data, writes output, and closes the files.
"""
def main():
    #Open the input file
    rf = open(os.path.join(os.getcwd(), "C-small-attempt2.in"), "r")
    #Open the output file
    wf = open(os.path.join(os.getcwd(), "output.txt"), "w")

    heading = True
    test_num = 1

    #Iterate through the input file
    while True:
        #read input one line at a time
        line = rf.readline()
        line = line.strip()

        if not line:
            #end of file

            #close input file
            rf.close()
            #close output file
            wf.close()
            break
        else:
            #process the line

            if (heading):
                heading = False
                NUM_TEST_CASES = int(line)
            else:
                #print the output
                wf.write("Case #" + str(test_num) + ":\n" + process(line) + "\n")
                #increment the test case number
                test_num += 1

main()
