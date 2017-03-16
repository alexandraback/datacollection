import string

letters = string.ascii_lowercase
table = 'yhesocvxduiglbkrztnwjpfmaq'

reader = open("A.in",'r')

num = int(reader.readline())

for i in range(num):
	text = reader.readline()
	print ("Case #%s: %s" %(i+1,text.translate(string.maketrans(letters,table)))).replace('\n','')
	
