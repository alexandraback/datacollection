import sys
import re
def reverse_sublist(s,start,end):
    lst = list(s)
    lst[start:end] = lst[start:end][::-1]
    return "".join(lst)
def toggle_sublist(s,start,end):
    lst = list(s)
    tmp="".join(lst[start:end])
    lst[start:end] = tmp.replace("a", "c")
    tmp="".join(lst[start:end])
    lst[start:end] = tmp.replace("b", "a")
    tmp="".join(lst[start:end])
    lst[start:end] = tmp.replace("c", "b")
    return "".join(lst)

def flip(s,start,end):
    return toggle_sublist(reverse_sublist(s,start,end),start,end)

def get_longest_seq(my_str, l):
    r = re.compile("("+l+"+"+l+")").findall(my_str)
    if len(r):return max(r)
    else: return None

def solve(s):
    #print("STATE:",file=sys.stderr)
    #print(s,file=sys.stderr)
    if s.find("b")==-1 or len(s)==0:
        return 0
    if s[0]=="a":
        pos = s.rfind("b")
        seq = get_longest_seq(s[0:pos],"a")
        if seq == None:
            pos = s.find("b")
            s = flip(s,0,pos)
            return 1 + solve(s)
        else:
            pos = s.find(seq)
            pos += len(seq)
            s = flip(s,0,pos)
            return 1 + solve(s)
    else:
        pos = s.rfind("b")+1
        s=flip(s,0,pos)
        return 1 + solve(s)



t = int(input())
for i in range(1,t+1):
    s = input()
    s = s.replace("+","a")
    s = s.replace("-","b")
    print("Case #"+str(i)+": "+str(solve(s)))

#print(toggle_sublist("aaabbbaaa",0,6))

#print(get_longest_seq("aaaabbbaba"))
#print(flip("abba",0,5))
