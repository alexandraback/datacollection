# Problem is here:
# https://code.google.com/codejam/contest/6224486/dashboard
filename = 'A-large.in'

def get_num_friends(s):
    "s is the string representing the audience"
    num_people_standing = 0
    num_friends_reqd = 0
    for i, ch in enumerate(s):  
        if num_people_standing < i:
            num_friends_reqd += 1
            num_people_standing += 1
        num_people_standing += int(ch)  
        
    return num_friends_reqd

if __name__ == "__main__":
    file = open(filename)
    fileout = open(filename.split('.')[0] + '.out', 'w')
    t = int(file.readline())
    for i in range(t):
        n, s = file.readline().split()
        fileout.write("Case #{}: {}\n".format(i + 1, get_num_friends(s)))
    
    fileout.close()
    print("done")
