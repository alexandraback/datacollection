import math

with open("C-small-attempt0.in", "r") as data:
    cases = int(data.readline())
    length, obj = (int(x) for x in data.readline().split(" "))
    with open("C-small-attempt0.out", "w") as result:
        result.write("Case #1:\n")
        num = 2**(length-1) + 1
        score = 0
        while score < obj:
            b_num = bin(num)[2:]
            factor = ""
            got_it = True
            for base in range(2, 11):
                num_base = 0
                j = 0
                for digit in b_num[::-1]:
                    if digit == "1":
                        num_base += base**j
                    j += 1
                success = False
                for k in range(2, 100):
                    if num_base % k == 0:
                        factor += " " + str(k)
                        success = True
                        break
                if not success:
                    got_it = False
                    break
            if got_it:
                result.write(b_num + factor + "\n")
                score += 1
            num += 2
                
                
        
        
