import sys
import os, os.path

def reverse(n):
    ret = 0
    while n > 0:
        ret = (ret * 10) + (n % 10)
        n = n // 10
    return ret

def is_palindrome(x):
    return x == reverse(x)

def count(a, b):
    even = [11, 22]
    odds = [1, 2, 3]

    small_inserts = ["0", "1", "2", "3"]
    large_inserts = ["00", "11", "22", "33"]

    count = 0
    while True:
        for o in odds:
            if a <= o*o <= b:
                count += 1
            if o*o > b:
                return count
            #print(o, o*o, count)
        for e in even:
            if a <= e*e <= b:
                count += 1
            if e*e > b:
                return count
            #print(e, e*e, count)

        new_even, new_odd = [], []
        for e in even:
            se = str(e)
            fp, sp = se[:len(se)//2], se[len(se)//2:]
            #print(e, se, fp, sp)
            for si in small_inserts:
                no = int(fp + si + sp)
                if is_palindrome(no*no):
                    new_odd.append(no)
            for li in large_inserts:
                ne = int(fp+li+sp)
                #print("NE: ", ne, ne*ne)
                if is_palindrome(ne*ne):
                    new_even.append(ne)
        #print(new_even, new_odd)
        even, odds = sorted(new_even), sorted(new_odd)

def main():
    input_path = sys.argv[1]
    output_path = os.path.splitext(input_path)[0] + ".out"
    output = []
    with open(input_path) as input_file:
        num_cases = int(input_file.readline().strip())

        for i in range(num_cases):
            a, b = map(int, input_file.readline().strip().split(" "))
            c = count(a, b)
            output.append("Case #{0}: {1}".format(i + 1, c))
            print(i)

    with open(output_path, "w") as output_file:
        for o in output:
            output_file.write(o + "\n")

if __name__ == "__main__":
    main()
