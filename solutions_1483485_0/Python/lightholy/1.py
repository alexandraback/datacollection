n = int(raw_input())
d = "yhesocvxduiglbkrztnwjpfmaq"
for i in range(n):
	s = raw_input()
	ans = "Case #" + str(i+1) + ": "
	for a in s:
		if a == " ":
			ans += " "
		else:
			ans += d [ord(a)-ord("a")]
	print (ans)
