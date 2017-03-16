import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def main(S):
    n0 = S.count("Z")
    n2 = S.count("W")
    n4 = S.count("U")
    n6 = S.count("X")
    n8 = S.count("G")
    n1 = S.count("O")-n0-n2-n4
    n3 = S.count("R")-n0-n4
    n5 = S.count("F")-n4
    n7 = S.count("V")-n5
    n9 = (S.count("N")-n7-n1)//2
    return ("0"*n0 + "1"*n1 + "2"*n2 + "3"*n3 + "4"*n4
            + "5"*n5 + "6"*n6 + "7"*n7 + "8"*n8 + "9"*n9)
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        S = input()
        
        ## Processing
        res = main(S)

        ## Output
        print("Case #{}: {}".format(c+1,res))


