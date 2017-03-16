fout = open("output.txt", "w")

def solve(s, j):
    global l
    curr = 0
    ans1 = ''
    ans2 = ''
    while curr != len(s) and ((s[curr] not in '1234567890' or j[curr] not in '1234567890') or s[curr] == j[curr]):
        if s[curr] == j[curr]:
            if s[curr] == '?':
                ans1 += '0'
                ans2 += '0'
            else:
                ans1 += s[curr]
                ans2 += s[curr]            
        elif s[curr] not in '1234567890':
            ans1 += j[curr]
            ans2 += j[curr]
        elif j[curr] not in '1234567890':
            ans2 += s[curr]
            ans1 += s[curr]
        curr += 1
    if curr != len(s):
        if int(s[curr]) > int(j[curr]):
            big = s
        else:
            big = j
    while curr != len(s):
        if s[curr] in '1234567890' and j[curr] in '1234567890':
            ans1 += s[curr]
            ans2 += j[curr]
        elif s[curr] in '1234567890':
            ans1 += s[curr]
            if big == s:
                ans2 += '9'
            else:
                ans2 += '0'
        elif j[curr] in '1234567890':
            ans2 += j[curr]
            if big == j:
                ans1 += '9'
            else:
                ans1 += '0'
        else:
            if big == s:
                ans1 += '0'
                ans2 += '9'
            else:
                ans1 += '9'
                ans2 += '0'
        curr += 1
    fout.write("Case #" + str(l) + ": " + ans1 + " " + ans2 + "\n")
    
n = int(input())
for l in range(1, n + 1):
    s, j = input().split()
    solve(s, j)
fout.close()