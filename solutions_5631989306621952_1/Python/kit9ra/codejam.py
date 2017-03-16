f = open("input.txt", "r")
g = open("output.txt", "w")

t = int(f.readline())

for tc in range (1, t + 1):
    
    
    data = f.readline()
    
    ans = ""
    
    for i in data:
        if not ans or i >= ans[0]:
            ans = i + ans
        else:
            ans = ans + i
            
    g.write("Case #{}: {}\n".format(tc, ans))    

f.close()
g.close()