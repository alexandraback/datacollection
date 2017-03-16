"""
Jonathan Simowitz

Google Code Jam 2012
Round 1B
"""

import os

"""
This object contains...
"""
class object():
    def __init__(self, data):
        self.data = data

    def __str__(self):
        return str(self.data)

"""
Funciton responsible for applying the algorithm
on the test data and returning the output
"""
def process(data):
    S = data.split()
    S = S[1:]
    for i in range(len(S)):
        S[i] = int(S[i])
    X = sum(S)
    total = X * 2
    target_score = float(total) / float(len(S))
    votes = []
    excempt = 0
    for score in S:
        if score >= target_score:
            excempt += 1
            total -= score
    target_score = float(total) / (float(len(S)) - float(excempt))
    for score in S:        
        points_needed = float(target_score) - float(score)
        if points_needed <= 0:
            votes.append(0.0)
        else:
            perc = points_needed/float(X)*100.0
            votes.append(perc)
    output = ""
    for percent in votes:
        output += str(percent) + " "
    return output.strip()

"""
Main function initializes files, iterates through
data, writes output, and closes the files.
"""
def main():
    #Open the input file
    rf = open(os.path.join(os.getcwd(), "A-large.in"), "r")
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
                wf.write("Case #" + str(test_num) + ": " + process(line) + "\n")
                #increment the test case number
                test_num += 1

main()
