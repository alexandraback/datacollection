
# coding: utf-8

# In[2]:

def str2num(s, base):
    # string to number
    out = 0;
    val = 1;
    for digit in reversed(s):
        if digit == '1':
            out += val;
        val *= base;
    return(out);


res = [];
path = [];
d = list(range(2, 13, 2));
def gen_res(res, val, d, i):
    if i == len(d):
        res.append(val);
        return
    gen_res(res, val ,d,  i+1)
    gen_res(res, val+ 2**d[i],d, i+1);
    
gen_res(res, 1+2**14, d, 0);

res_str = list(map(lambda x: bin(3*x)[2:], res))[:50];

out = [];
for i in range(len(res_str)):
    tmp = [];
    for base in range(2, 11):
        num = res_str[i];
        tmp.append(base+1);
        assert str2num(num, base) % (base+1) == 0;
            
        
    out.append((num, tmp));

# output 
with open('C-small.out', 'w') as fout:
    fout.write('Case #1:\n');
    for i in range(len(out)):
        line = out[i][0] + ' ' + ' '.join(map(str, out[i][1])) + '\n';
        fout.write(line);
        
               

