
# coding: utf-8

# In[17]:

import numpy as np
from collections import Counter



# In[127]:

num = int(raw_input())
data = []

for i in range(num):
    data.append(str(raw_input()).split(' '))


# In[28]:

def isint(x):
    try: 
        int(x)
        return True
    except:
        return False


# In[59]:

def replace(x, a):
    return [a if t == '?' else t for t in x]


# In[69]:

def sub(x, y):
    return int(''.join(x)) - int(''.join(y))


# In[164]:

def pro_b(x, y):
    x = list(x)
    y = list(y)
    
    l = len(x)
    tmp = (x, y, 1e20)
    for i in range(l):
        #print 'digit', i
        if (x[i] == '?') & (y[i] == '?'):
            xx = np.copy(x)
            yy = np.copy(y)
            xx[i] = '0'
            yy[i] = '1'
            xx = replace(xx, '9')
            yy = replace(yy, '0')
            xy = sub(yy, xx)
            if xy < tmp[2]:
                tmp = (xx, yy, xy)
            elif xy == tmp[2]:
                if int(''.join(xx)) < int(''.join(tmp[0])):
                    tmp = (xx, yy, xy)
                elif int(''.join(xx)) == int(''.join(tmp[0])):
                    if int(''.join(yy)) < int(''.join(tmp[1])):
                        tmp = (xx, yy, xy)
            #print tmp                 
            
            xx = np.copy(x)
            yy = np.copy(y)
            xx[i] = '1'
            yy[i] = '0'
            xx = replace(xx, '0')
            yy = replace(yy, '9')
            xy = sub(xx, yy)
            if xy < tmp[2]:
                tmp = (xx, yy, xy)
                #print tmp 
            elif xy == tmp[2]:
                if int(''.join(xx)) < int(''.join(tmp[0])):
                    tmp = (xx, yy, xy)
                elif int(''.join(xx)) == int(''.join(tmp[0])):
                    if int(''.join(yy)) < int(''.join(tmp[1])):
                        tmp = (xx, yy, xy)
            
            x[i] = '0'
            y[i] = '0'

        if (isint(x[i]) & isint(y[i])):
            if (int(x[i]) > int(y[i])):
                xx = replace(x, '0')
                yy = replace(y, '9') 
                xy = sub(xx, yy)
                if xy < tmp[2]:
                    tmp = (xx, yy, xy)
                        #print tmp
                elif xy == tmp[2]:
                    if int(''.join(xx)) < int(''.join(tmp[0])):
                        tmp = (xx, yy, xy)
                    elif int(''.join(xx)) == int(''.join(tmp[0])):
                        if int(''.join(yy)) < int(''.join(tmp[1])):
                            tmp = (xx, yy, xy)
                break
            if (int(y[i]) > int(x[i])):
                yy = replace(y, '0')
                xx = replace(x, '9')
                xy = sub(yy, xx)
                if xy < tmp[2]:
                    tmp = (xx, yy, xy)
                    #print tmp
                elif xy == tmp[2]:
                    if int(''.join(xx)) < int(''.join(tmp[0])):
                        tmp = (xx, yy, xy)
                    elif int(''.join(xx)) == int(''.join(tmp[0])):
                        if int(''.join(yy)) < int(''.join(tmp[1])):
                            tmp = (xx, yy, xy)
                break
            if x[i] == y[i]:
                pass
        
        else:
            if x[i] == '?':
                if int(y[i]) < 9:
                    xx = np.copy(x)
                    yy = np.copy(y)
                    xx[i] = str(int(yy[i]) + 1)
                    xx = replace(xx, '0')
                    yy = replace(yy, '9')
                    xy = sub(xx, yy)
                    if xy < tmp[2]:
                        tmp = (xx, yy, xy)
                        #print tmp
                    elif xy == tmp[2]:
                        if int(''.join(xx)) < int(''.join(tmp[0])):
                            tmp = (xx, yy, xy)
                        elif int(''.join(xx)) == int(''.join(tmp[0])):
                            if int(''.join(yy)) < int(''.join(tmp[1])):
                                tmp = (xx, yy, xy)
                if int(y[i]) > 0:
                    xx = np.copy(x)
                    yy = np.copy(y)
                    xx[i] = str(int(yy[i]) - 1)
                    xx = replace(xx, '9')
                    yy = replace(yy, '0')
                    xy = sub(yy, xx)
                    if xy < tmp[2]:
                        tmp = (xx, yy, xy)
                        #print tmp
                    elif xy == tmp[2]:
                        if int(''.join(xx)) < int(''.join(tmp[0])):
                            tmp = (xx, yy, xy)
                        elif int(''.join(xx)) == int(''.join(tmp[0])):
                            if int(''.join(yy)) < int(''.join(tmp[1])):
                                tmp = (xx, yy, xy)
                x[i] = y[i]
                
            if y[i] == '?':
                if int(x[i]) < 9:
                    xx = np.copy(x)
                    yy = np.copy(y)
                    yy[i] = str(int(xx[i]) + 1)
                    xx = replace(xx, '9')
                    yy = replace(yy, '0')
                    xy = sub(yy, xx)
                    if xy < tmp[2]:
                        tmp = (xx, yy, xy)
                        #print tmp
                    elif xy == tmp[2]:
                        if int(''.join(xx)) < int(''.join(tmp[0])):
                            tmp = (xx, yy, xy)
                        elif int(''.join(xx)) == int(''.join(tmp[0])):
                            if int(''.join(yy)) < int(''.join(tmp[1])):
                                tmp = (xx, yy, xy)
                if int(x[i]) > 0:
                    xx = np.copy(x)
                    yy = np.copy(y)
                    yy[i] = str(int(xx[i]) - 1)
                    xx = replace(xx, '0')
                    yy = replace(yy, '9')
                    xy = sub(xx, yy)
                    if xy < tmp[2]:
                        tmp = (xx, yy, xy)
                        #print tmp
                    elif xy == tmp[2]:
                        if int(''.join(xx)) < int(''.join(tmp[0])):
                            tmp = (xx, yy, xy)
                        elif int(''.join(xx)) == int(''.join(tmp[0])):
                            if int(''.join(yy)) < int(''.join(tmp[1])):
                                tmp = (xx, yy, xy)
            
                y[i] = x[i]
                
    #print x, y
    #print tmp[2]
    try:
        xy = np.abs(sub(x, y))
        if xy < tmp[2]:
            tmp = (x, y, xy)
            #print tmp
        elif xy == tmp[2]:
            if int(''.join(xx)) < int(''.join(tmp[0])):
                tmp = (xx, yy, xy)
            elif int(''.join(xx)) == int(''.join(tmp[0])):
                if int(''.join(yy)) < int(''.join(tmp[1])):
                    tmp = (xx, yy, xy)
        #print tmp
    except:
        pass
    
    return ''.join(tmp[0]), ''.join(tmp[1])


# In[165]:

for i in range(num):
    print 'Case #{}: {} {}'.format(i+1, pro_b(data[i][0],data[i][1])[0], pro_b(data[i][0],data[i][1])[1])


# In[ ]:



