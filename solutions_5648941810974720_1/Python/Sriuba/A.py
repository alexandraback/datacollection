#GJAM
#inn.in
from sys import * 

def execute():
        input_name = argv[1]
        output_name = "out.txt"
        input_file = open(input_name)
        output_file = open(output_name, 'w')

        main(input_file, output_file)

        input_file.close()
        output_file.close()

def main(input_file, output):
        # main algorithm goes here
        words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
        T = int(next(input_file))
        for i in range(T):
                S = next(input_file).strip()
                dic = {'E':0, 'G':0, 'F':0, 'I':0, 'H':0, 'O':0, 'N':0, 'S':0, 'R':0, 'U':0, 'T':0, 'W':0, 'V':0, 'X':0, 'Z':0}
                for letter in S:
                        dic[letter] += 1
                digits = []

                order = ['Z', 'W', 'X', 'G', 'S', 'V', 'H', 'R', 'O', 'I']
                nums  = [0, 2, 6, 8, 7, 5, 3, 4, 1, 9]
                
                for j in range(len(order)):
                        digits = digits + [nums[j]] * dic[order[j]] 
                        sub = dic[order[j]]
                        for letter in words[nums[j]]: 
                                dic[letter] -= sub 
                s = "".join([str(t) for t in sorted(digits)])
                output.write("Case #" + str(i + 1) + ": " + str(s) + "\n")

execute()
