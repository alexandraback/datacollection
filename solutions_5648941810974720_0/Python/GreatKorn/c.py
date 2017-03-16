d = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
fout = open("output.txt", "w")

def solve(arr, ans = []):
    global l
    if len(arr) == 0:
        ans.sort()
        fout.write("Case #" + str(l) + ": " + "".join(map(str, ans)) + "\n")
    if 'X' in arr:
        for i in d[6]:
            arr.remove(i)
        solve(arr, ans + [6])
    elif 'Z' in arr:
        for i in d[0]:
            arr.remove(i)
        solve(arr, ans + [0])
    elif 'W' in arr:
        for i in d[2]:
            arr.remove(i)
        solve(arr, ans + [2])
    elif 'U' in arr:
        for i in d[4]:
            arr.remove(i)
        solve(arr, ans + [4])
    elif 'S' in arr:
        for i in d[7]:
            arr.remove(i)
        solve(arr, ans + [7])
    elif 'O' in arr:
        for i in d[1]:
            arr.remove(i)
        solve(arr, ans + [1])
    elif 'F' in arr:
        for i in d[5]:
            arr.remove(i)
        solve(arr, ans + [5])
    elif 'N' in arr:
        for i in d[9]:
            arr.remove(i)
        solve(arr, ans + [9])
    elif 'I' in arr:
        for i in d[8]:
            arr.remove(i)
        solve(arr, ans + [8])
    elif 'T' in arr:
        for i in d[3]:
            arr.remove(i)
        solve(arr, ans + [3])
    else:
        return

n = int(input())
for l in range(1, n + 1):
    s = list(input())
    solve(s)
fout.close()