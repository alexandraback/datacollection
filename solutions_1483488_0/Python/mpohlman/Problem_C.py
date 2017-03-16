#!/usr/bin/env python

def recycle_count(A,B):
    A_list=[int(i) for i in list(str(A))]
    B_list=[int(i) for i in list(str(B))]
    ndigits=len(A_list)
    pairs=[]
    for n in range(A,B):
        n_list=[int(i) for i in list(str(n))]
        m_list=n_list
        for index in range(1,ndigits):
            m_list=n_list[index:] + n_list[:index]
            #print A_list, n_list, m_list, B_list
            if A_list <= n_list and n_list < m_list and m_list <=B_list:
                pairs.append(int(''.join([str(c) for c in (n_list+m_list)])))
    pairs.sort()
    #print pairs
    #print len(pairs)
    myset=set(pairs)
    #print myset
    #print len(myset)
    return len(myset)
        

#infile=open('input_example.in','r')
infile=open('C-small-attempt0.in','r')
#infile=open('C-large.in','r')

line=infile.readline()
T=int(line)
#print T
for index in range(T):
    A,B=[int(i) for i in infile.readline().split()]
    #print A,B
    blah=recycle_count(A,B)
    print 'Case #%(index)d: %(answer)d' % {"index":index+1,"answer":blah}
infile.close()
