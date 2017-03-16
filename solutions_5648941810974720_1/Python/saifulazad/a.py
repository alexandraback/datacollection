__author__ = 'Azad'
def fun(s):
    dig = [0]*10
   # print dig
    l = ['Z', 'W', 'U', 'X' , 'G']
    r = ['ERO', 'TO', 'FOR', 'SI', 'EIHT']

    ty = {'Z': 0 ,'W':2 , 'U':4 , 'X': 6, 'G':8}
    new_dict = {}
    mp = dict(zip(l,r))

    sor = list(s)

    al = set(sor)

    pair = {x:sor.count(x)for x in al}

    #print pair

    for val in mp:
        if val in pair.keys():

            r =pair[val]
            dig[ty[val]] =r
            new_dict[val] = r
            pair[val] -= r
            li = mp[val]
            for x in li:
                pair[x] -= r



    filtered_dict = {k:v for (k,v) in pair.items() if v !=0}
    # print new_dict
    # print filtered_dict

    pair =filtered_dict

    l = ['O',  'F',]
    r = ['NE', 'IVE']
    ty = {'O': 1 ,'F':5}
    mp = dict(zip(l,r))

    for val in mp:
        if val in pair.keys():

            r =pair[val]
            dig[ty[val]] = r
            new_dict[val] = r
            pair[val] -= r
            li = mp[val]
            for x in li:
                pair[x] -= r



    filtered_dict = {k:v for (k,v) in pair.items() if v !=0}
    pair =filtered_dict
    l = ['H',  'S']
    r = ['TREE',  'EVEN']
    ty = {'H': 3 ,'S':7}
    mp = dict(zip(l,r))

    for val in mp:
        if val in pair.keys():

            r =pair[val]
            dig[ty[val]] = r
            new_dict[val] = r
            pair[val] -= r
            li = mp[val]
            for x in li:
                pair[x] -= r



    filtered_dict = {k:v for (k,v) in pair.items() if v !=0}
    pair =filtered_dict

    if 'I' in pair:
        dig[9] = pair['I']

    return ''.join([str(x)*dig[x] for x in range(10)])


r = open('a.txt','r')
r = open('a.txt','r')
text_file = open("Output.txt", "w")
n = int(r.readline())

t = [(r.readline()) for x in xrange(n)]
c =1

for x in t:
    text_file.writelines('Case #{0}: {1}\n' .format(c,fun(x)))
    print 'Case #{0}: {1}' .format(c,fun(x))
    c+=1

