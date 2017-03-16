import sys
import io

def isPalindrome(num):
    str_num = str(num)

    for i in range(0, len(str_num)-1):
        if str_num[i] != str_num[len(str_num) - 1 - i]:
            return False
    
    return True

def precompute():
    nums = []
    count = 1

    while True:
        
        if isPalindrome(count):
            if isPalindrome(count * count):
                nums.append(count * count)
            
        if count > 10 ** 7:
            break

        count += 1
    return nums

#all_palindromes = precompute()
all_palindromes = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001]

def countPalindromes(strt, end):
    count = 0
    
    for i in all_palindromes:
        if i >= strt and i <= end:
            count+=1
    return count

if __name__ == "__main__":
    #print all_palindromes
    #print "Enter Cases: "
    
    n_cases = input()

    for i in range(n_cases):
        a = map(int, raw_input().split())
        #print "Case #",i+1,": ", countPalindromes(a[0], a[1])
        sys.stdout.write("Case #")
        sys.stdout.write(str(i+1))
        sys.stdout.write(": ")
        sys.stdout.write(str(countPalindromes(a[0], a[1])))
        sys.stdout.write("\n")
