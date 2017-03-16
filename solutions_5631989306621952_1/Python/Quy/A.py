__author__ = "Quy Doan"

import sys

input_file = sys.argv[1]
output_file = sys.argv[2]

with open(input_file,"r") as reader:
    with open(output_file, "w") as writer:
        '''Do stuffs'''
        num_of_test = int(reader.readline())
        for test in range(num_of_test):
            exam = reader.readline()
            res = ""
            for i in exam:
                if res == "":
                    res += i
                elif res[0] <= i:
                    res = i + res
                else:
                    res = res + i
            writer.write("Case #"+str(test+1)+": "+res)

                
