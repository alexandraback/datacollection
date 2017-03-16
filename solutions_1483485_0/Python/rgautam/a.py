f=open('/home/cscape/Downloads/A-small-attempt0 (1).in','r')
r_lines=f.readlines()
number_of_inputs=int(r_lines[0])
w_lines=[]
dict_alphabets={
    'a':'y','b':'h','c':'e','d':'s',
    'e':'o','f':'c','g':'v','h':'x',
    'i':'d','j':'u','k':'i','l':'g',
    'm':'l','n':'b','o':'k','p':'r',
    'q':'z','r':'t','s':'n','t':'w',
    'u':'j','v':'p','w':'f','x':'m',
    'y':'a','z':'q',' ':' ','\n':'\n'
    }
for i in range(number_of_inputs):
    line=r_lines[i+1]
    temp_line= ''
    for j in line:
        try:
            temp_line += dict_alphabets[j]
        except:
            temp_line += j
    w_lines.append('Case #%s'%(i+1)+': '+''.join(temp_line))
f=open('/home/cscape/Desktop/A-small-attempt0.out','w')
f.writelines(w_lines)
f.close()
